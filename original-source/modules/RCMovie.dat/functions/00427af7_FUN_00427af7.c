/*
 * FUN_00427af7 at 00427af7
 * uint * __cdecl FUN_00427af7(uint param_1, uint * param_2, size_t param_3)
 * Address ranges: 00427af7-00427bc7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * __cdecl FUN_00427af7(uint param_1,uint *param_2,size_t param_3)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  uint *puVar4;
  uint local_10c [65];
  LPSTR local_8;
  
  uVar3 = param_1;
  if (param_1 == 0) {
    DVar2 = GetCurrentDirectoryA(0x104,(LPSTR)local_10c);
  }
  else {
    iVar1 = FUN_00427bc8(param_1);
    if (iVar1 == 0) {
      _DAT_0043e2c0 = 0xd;
      DAT_0043e2c4 = 0xf;
      return (uint *)0x0;
    }
    param_1 = (uint)CONCAT12(0x2e,CONCAT11(0x3a,(char)uVar3 + '@'));
    DVar2 = GetFullPathNameA((LPCSTR)&param_1,0x104,(LPSTR)local_10c,&local_8);
  }
  if ((DVar2 != 0) && (uVar3 = DVar2 + 1, uVar3 < 0x105)) {
    if (param_2 == (uint *)0x0) {
      if ((int)uVar3 <= (int)param_3) {
        uVar3 = param_3;
      }
      puVar4 = _malloc(uVar3);
      if (puVar4 != (uint *)0x0) {
LAB_00427bb4:
        puVar4 = FUN_0041f7a0(puVar4,local_10c);
        return puVar4;
      }
      _DAT_0043e2c0 = 0xc;
    }
    else {
      puVar4 = param_2;
      if ((int)uVar3 <= (int)param_3) goto LAB_00427bb4;
      _DAT_0043e2c0 = 0x22;
    }
  }
  return (uint *)0x0;
}

