# 前缀树（TrieTree)
使用场景：多用于查询子集;特别是字符串中特殊子集

节点Node的结构在经典情况下，仅仅存放字符。

但是自定义Node中设置pass以及end用于表示**通过此节点的次数**，以及**以该节点为结束的个数**。

基本操作：
1. 插入
2. 删除
   删除时需要注意节点的释放，可以通过栈的方式临时存放待释放节点。
   > 注意：除了更新pass标记外，不要忘记更新end标记
3. 统计某个字符串出现次数
   遍历到字符串结尾对应的节点时，节点的end值为结果;
4. 统计以某个字符串为前缀的次数
   遍历到字符串结尾对应的节点时，节点的pass值代表以字符串为前缀的字符串的个数；
