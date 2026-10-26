/*
 * FUN_004055c9 at 004055c9
 * int * __cdecl FUN_004055c9(int param_1, int param_2)
 * Address ranges: 004055c9-00405645
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __cdecl FUN_004055c9(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint *_Size;
  uint *puVar3;
  
  _Size = (uint *)(param_1 * param_2);
  puVar3 = _Size;
  if (_Size < (uint *)0xffffffe1) {
    if (_Size == (uint *)0x0) {
      puVar3 = (uint *)0x1;
    }
    puVar3 = (uint *)((int)puVar3 + 0xfU & 0xfffffff0);
  }
  do {
    if (puVar3 < (uint *)0xffffffe1) {
      if ((_Size < DAT_004083bc || (int)_Size - (int)DAT_004083bc == 0) &&
         (piVar1 = FUN_00402e7e(_Size), piVar1 != (int *)0x0)) {
        _memset(piVar1,0,(size_t)_Size);
        return piVar1;
      }
      piVar1 = HeapAlloc(DAT_0040a01c,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_00408c5c == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_00403333(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}

