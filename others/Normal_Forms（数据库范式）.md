## 背景知识

Super key 超鍵 : 符合唯一性（uniquely identify every row）的關聯鍵。

Candidate Key 候選鍵 : 符合唯一性以及最小性的關聯鍵。

Primary Key 主鍵 : 從候選鍵中，挑選出其中一個關聯鍵，也就是最具識別意義的關聯鍵。 Alternate Key 次要鍵 : 沒有被選為主鍵的其他候選鍵。
Foreign Key 外鍵/外部鍵 : 關聯中被用來參考到其他表格主鍵的關聯鍵，就是外鍵。

prime attributes：attributes that are part of any candidate key.

For example:

```
R: {ABCD}
F: {AB -> C, ABD -> C, ABC -> D, AC -> D}
keys: AB
prime attributes: A, B
non-prime attributes: C, D
```

## Boyce–Codd normal form (or BCNF or 3.5NF)

**Def:** A relation R is in BCNF if:
If As → Bs is a non-trivial dependency in R , then As is a superkey for R.

总结一下：“In every FD, the left side is a superkey.”

缺陷：losing function dependency（FD），but BCNF is not data-lossy(Results can be rejoined to obtain the exact original).

## Third Normal Form(3NF)

**Def:** A relation R is in 3rd normal form if :
For every non-trivial dependency A1, A2, ..., An → B for R, {A1, A2, ..., An } is a super-key for R, or B is part of a key.

**备注：** 3NF比BCNF约束更少。关于"part of a key"：key = XYZ，B = XY，此时可以认为B是key的一部分。

**BCNF和3NF的Tradeoff:**
BCNF = no FD anomalies, but may lose some FDs.
3NF = keeps all FDs, but may have some anomalies(the decomposition is lossless).

**违反3NF的情况：**

首先回顾一下定义：Let R be a relation schema, F be the set of FDs given to hold over R, X be a subset of the attributes of R, and A be an attribute of R. R is in third normal form if, for every FD X →A in F, one of the following statements is true:

- A $\in$ X, this is, it is a trivial FD, or
- X is a superkey, or
- A is part of some key for R.

违反3NF的情况有两种：

- X is a proper subset of some key K. Such dependency is called a **partial dependency**. 举例来说，对于具有属性{A, B, C, D}的关系R, key: AB, FD: A→C。可以发现A是AB的真子集，此时称为**部分依赖**。

- X is not a proper subset of some key K. Such a dependency is called a **transitive dependency**. 举例来说K→X→A，此时称为**传递依赖**。

### 关于BCNF和3NF的例题

Consider a relation R with five attributions ABCDE. You are given the following dependencies: A→B, BC→E, and ED → A.

(a) List all keys for R.

(b) Is R in 3NF? Explain why or why not.

(b) Is R in BCNF? Explain why or why not.

解答：

(a) $\{\rm BCD\}^+$ = {ABCDE}

$\{\rm CDE\}^+$= {ABCDE}

$\{\rm ACD\}^+$= {ABCDE}

所以ACD, BCD, CDE是key

(b) ①对于 A→B, B 属于key BCD的一部分

②对于BC→E, E属于 key CDE的一部分

③对于ED→A, A属于 key ACD的一部分

因此R满足3NF

(c) 因为A→B中A不是superkey，所以R不属于BCNF

## Second Normal Form (2NF)

补充概念：

① The constituent attributes of candidate key are called **prime attributes**. Conversely, an attribute that does not occur in ANY candidate key is called a **non-prime attribute**.

② 第一范式：原子性，单一字段不能有多个值，就是每个field不能是个数组。

第二范式：

A relation is in the second normal form if it fulfills the following two requirements:

1. It is in first normal form.
2. It does not have any non-prime attribute that is on any proper subset of any candidate key of the relation. **A non-prime attribute of a relation** is an attribute that is not a part of any candidate key of the relation.

翻译成人话：FD中不存在部分依赖主键的属性
e.g.
R: {ABCD}
F:{AB→C, C→D}此时满足2NF
F∪{B→D}，此时不满足2NF，因为R的key为AB，B**部分依赖**key