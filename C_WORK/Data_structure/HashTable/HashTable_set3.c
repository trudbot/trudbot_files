/*
哈希表优化
再散列

在使用平方探测的开放定址法中， 当哈希表被填的太满， 操作的时间开销增大， 且Insert可能会失败。
再散列的思想是， 当遇到某种情况时(如哈希表满了一半或遇到插入失败)， 就把当前表中的元素都转移到一张更大的哈希表中(大约两倍), 舍弃当前的哈希表。

再散列让程序员再也不用担心表的大小
*/
#include "../Data_structure/HashTable_set2.c"

HashTable ReHash(HashTable H){//只写了reHash的例程， 当然insert也应该改变
    Cell* OldCells = H->Cells;
    int OldSize = H->size;
    free(H);

    //get a new table
    H = InitTable(2*OldSize);

    //scan through old table, reinserting into new table
    for(int i=0; i<OldSize; i++){
        if(OldCells[i].info == Legitimate){
            Insert(H, OldCells[i].Key, OldCells[i].val);
        }
    }

    free(OldCells);
    return H;
}
