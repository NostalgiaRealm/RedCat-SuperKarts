/*
 * FUN_004c87f5 at 004c87f5
 * undefined FUN_004c87f5(void)
 * Address ranges: 004c87f5-004c8871
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void * FUN_004c87f5(int param_1,int param_2)

{
  void *_Dst;
  LPVOID pvVar1;
  int iVar2;
  uint _Size;
  uint uVar3;
  
  _Size = param_1 * param_2;
  uVar3 = _Size;
  if (_Size < 0xffffffe1) {
    if (_Size == 0) {
      uVar3 = 1;
    }
    uVar3 = uVar3 + 0xf & 0xfffffff0;
  }
  do {
    if (uVar3 < 0xffffffe1) {
      if ((_Size < DAT_005031e4 || _Size - DAT_005031e4 == 0) &&
         (_Dst = (void *)FUN_004c66a6(_Size), _Dst != (void *)0x0)) {
        _memset(_Dst,0,_Size);
        return _Dst;
      }
      pvVar1 = HeapAlloc(DAT_006b6da0,8,uVar3);
      if (pvVar1 != (LPVOID)0x0) {
        return pvVar1;
      }
    }
    if (DAT_006b67bc == 0) {
      return (void *)0x0;
    }
    iVar2 = FUN_004c62bb(uVar3);
  } while (iVar2 != 0);
  return (void *)0x0;
}

