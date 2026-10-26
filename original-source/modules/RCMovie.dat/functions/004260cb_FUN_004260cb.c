/*
 * FUN_004260cb at 004260cb
 * int * __cdecl FUN_004260cb(int param_1, int param_2)
 * Address ranges: 004260cb-00426147
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __cdecl FUN_004260cb(int param_1,int param_2)

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
      if ((_Size < DAT_00437490 || (int)_Size - (int)DAT_00437490 == 0) &&
         (piVar1 = FUN_00422ebb(_Size), piVar1 != (int *)0x0)) {
        _memset(piVar1,0,(size_t)_Size);
        return piVar1;
      }
      piVar1 = HeapAlloc(DAT_0043f81c,8,(SIZE_T)puVar3);
      if (piVar1 != (int *)0x0) {
        return piVar1;
      }
    }
    if (DAT_0043e578 == 0) {
      return (int *)0x0;
    }
    iVar2 = FUN_004262e6(puVar3);
  } while (iVar2 != 0);
  return (int *)0x0;
}

