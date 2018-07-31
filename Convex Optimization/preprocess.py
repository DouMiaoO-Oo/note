# -*- coding: utf-8 -*-
# !usr/bin/env python3 

""" 代码任务
# 想把markdown中的链接替换一下格式
# markdown中格式长这样： ![内容描述](内容链接)
# 想替换成: $$ 内容描述 $$
# 匹配的正则表达式是： \!\[.*\]\(.*\)
""" 

""" Reference
# Python re 模块学习 http://www.runoob.com/python/python-reg-expressions.html
# 正则表达式group的理解 https://www.cnblogs.com/erichuo/p/7909180.html
# 正则表达式之非贪婪匹配(最短匹配) https://www.cnblogs.com/jhao/p/5989241.html
"""
import re

file_name = "3.1.7 上镜图 epigraph.md"
def read_file(name):
	with open(name, "r", encoding="utf8") as rf:
		lines = rf.readlines()
	return "".join(lines)


def replace(matched):  # group 其实可以起名字: (?P<group_name>.*)
	LaTeX_math = matched.group(1)  # 匹配到的LaTeX公式部分. 
	print(LaTeX_math)
	print(LaTeX_math[1:-1])
	return "$$" + LaTeX_math[1:-1] + "$$"
	
	
"""
# 中间有一个分组group，用来拿到内容描述的部分。
# *是贪婪匹配，补充一个`?`可以得到最短匹配
"""
pattern_str = "\!(\[.*?\])\(.*?\)"
# pattern = re.compile(pattern_str)  # 生成一个Pattern 对象，方便后面的使用
file_content = read_file(file_name)
# print(repr(file_content))

res = re.sub(pattern_str, replace, file_content)
with open(file_name.rstrip(".md")+"_processed.md", "w", encoding="utf8") as wf:
	wf.write(res)