% 2019.3.18 刘宇威
% OCTAVE代码，数组下标从1开始。
% 这份KD-tree的实现是用连续的数组结构实现的，应该用指针？ 他的数据点没有排序，只是在排序下标。
% 参考链接：https://sine-x.com/statistical-learning-method/#%E7%AC%AC3%E7%AB%A0-k%E9%82%BB%E8%BF%91%E7%AE%97%E6%B3%95
count = 100;
dimen = 100;
test = 100;

function ret = distance(a, b)  % a是行向量，b是矩阵？
	ret = sqrt(sum((a.-b).^2,2));
end

function ret = find_k_nearest_naive(x, p, k)  % 拿来对照的标准KNN算法
	[val, r] = sort(distance(x,p));  % r应该是排序之后的下标
	ret = r(1:k);
end

function ret = kdtree_build_recur(x, r, d)
	% x：样本点*样本的维度  r:当前区域内样本的下标  d: 当前节点处理的维度
	
	count = length(r);  % r 这个维度下的点个数
	dimen = size(x, 2);  % 矩阵x的第二个维度是样本点的维度
	if (count == 1)
		ret = struct('point', r(1), 'dimen', d);  % point: 区域内点的下标  "dimen": 当前节点处理的维度
	else
		mid = ceil(count / 2);
		ret = struct('point', r(mid), 'dimen', d);  % 当前节点上的值
		d = mod(d, dimen)+1;  
		% Build left sub tree
		if (mid > 1)
			left = r(1:mid-1);  % 子树需要处理的样本序号
			leftxd = x(left,d); % 子树需要处理的样本在d维上的取值
			[val, leftrr] = sort(leftxd);  % 子树需要处理的样本在d维上的取值的排序
			leftr = left(leftrr);  % % 子树需要处理的样本在d维上的取值，按照从小到大重新排列
			ret.left = kdtree_build_recur(x, leftr, d);
		end
		% Build right sub tree
		if (count > mid)
			right = r(mid+1:count);
			rightxd = x(right,d);
			[val, rightrr] = sort(rightxd);
			rightr = right(rightrr);
			ret.right = kdtree_build_recur(x, rightr, d);
		end
	end
end

function ret = kdtree_build(x)  % 建立kd树
	[val, r] = sort(x(:,1));    % 在第一个维度上排序，也就是矩阵x的第一列
	ret = struct('data',x,'root', kdtree_build_recur(x, r, 1));  % data: x    root: kdtree_build_recur(x, r, 1)
end

function ret = kdtree_cand_fartest(x, p, cand)
	% x：样本点*样本的维度
	% p: 预测用的样本点 （向量）
	% cand:	k近邻候选向量的集合，是个list，内容是样本的下标
	[val, index] = max(distance(x, p)(cand));  % 计算x和p的距离，然后取出cand(样本下标)中的样本点
	ret = cand(index);
end

function ret = kdtree_cand_insert(x, p, cand, k, point)
	 % 刘宇威：使用这个函数是保证要用point替换cand中最远的近邻
	if (length(cand) < k)
		ret = [cand; point];
	else
		fartest = kdtree_cand_fartest(x, p, cand);  % 找到cand中距离p最远的
		cand(find(cand == fartest)) = point;  % 替换距离p最远的近邻
		ret = cand;
	end 
end

function ret = kdtree_find_recur(x, node, p, ret, k)
	% x：样本点个数*样本的维度矩阵
	% node: 当前位于kd-tree上的节点 
	% p: 预测用的样本点 （向量）
	% ret:	k近邻候选向量的集合，是个list，内容是样本的下标
	% lyw: 先深度遍历找到叶子节点，然后回溯回来判断是否需要把祖先节点插入进kd-tree。
	% 先左（右）子节点 → 当前节点 → 最后检查与右（左）节点的区间是否有交集，再决定是否遍历该子节点
	point = node.point;
	d = node.dimen;
	if (p(d) < x(point, d) )
		% Search in left sub tree
		if (isfield(node, 'left')) % lyw: 存在左子树，则先遍历left
			ret = kdtree_find_recur(x, node.left, p, ret, k);
		end
		% Add current point if neccessary
		fartest = kdtree_cand_fartest(x, p, ret);
		if (length(ret) < k || distance(x(point,:),p) < distance(x(fartest,:),p))
			ret = kdtree_cand_insert(x, p, ret, k, point);
		end
		% Search in right sub tree if neccessary
		fartest = kdtree_cand_fartest(x, p, ret);
		radius = distance(x(fartest,:), p);         %    以p为圆心，距离最远的k近邻的距离为半径， 与right子树的区间有交集
		if (isfield(node, 'right') && (length(ret) < k || p(d) + radius > x(point,d)))
			ret = kdtree_find_recur(x, node.right, p, ret, k);
		end
	else
		% Search in right sub tree
		if (isfield(node, 'right'))
			ret = kdtree_find_recur(x, node.right, p, ret, k);
		end
		% Add current point if neccessary
		fartest = kdtree_cand_fartest(x, p, ret);
		if (length(ret) < k || distance(x(point,:),p) < distance(x(fartest,:),p))
			ret = kdtree_cand_insert(x, p, ret, k, point);
		end
		% Search in left sub tree if neccessary
		fartest = kdtree_cand_fartest(x, p, ret);
		radius = distance(x(fartest,:),p);
		if (isfield(node, 'left') && (length(ret) < k || p(d) - radius <= x(point,d)))
			ret = kdtree_find_recur(x, node.left, p, ret, k);
		end
	end
end

function ret = kdtree_find(tree, p, k)
	% tree: kd-tree, p: 用来预测的样本点, k: 
	x = tree.data;
	root = tree.root;
	ret = kdtree_find_recur(x, root, p, [], k);
end

correct = 0;
for i = 1:test
	x = rand(count, dimen);  % count* dimen的样本
	y = rand(1, dimen);      % 用来预测的样本
	k = ceil(rand(1,1)*count);
	ret = kdtree_build(x);
	a = sort(kdtree_find(ret, y, k));
	b = sort(find_k_nearest_naive(x, y, k));
	correct += sum(a == b) == k;
end
printf('correct:%d/%d\n', correct, test);