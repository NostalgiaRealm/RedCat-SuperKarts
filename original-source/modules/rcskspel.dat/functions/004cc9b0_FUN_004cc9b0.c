/*
 * FUN_004cc9b0 at 004cc9b0
 * undefined FUN_004cc9b0(void)
 * Address ranges: 004cc9b0-004cca80
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004cc9b0(uint param_1,void *param_2,size_t param_3)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  CHAR local_10c [260];
  LPSTR local_8;
  
  uVar3 = param_1;
  if (param_1 == 0) {
    DVar2 = GetCurrentDirectoryA(0x104,local_10c);
  }
  else {
    iVar1 = FUN_004cca81(param_1);
    if (iVar1 == 0) {
      _DAT_006b66e8 = 0xd;
      DAT_006b66ec = 0xf;
      return 0;
    }
    param_1 = (uint)CONCAT12(0x2e,CONCAT11(0x3a,(char)uVar3 + '@'));
    DVar2 = GetFullPathNameA((LPCSTR)&param_1,0x104,local_10c,&local_8);
  }
  if ((DVar2 != 0) && (uVar3 = DVar2 + 1, uVar3 < 0x105)) {
    if (param_2 == (void *)0x0) {
      if ((int)uVar3 <= (int)param_3) {
        uVar3 = param_3;
      }
      pvVar4 = _malloc(uVar3);
      if (pvVar4 != (void *)0x0) {
LAB_004cca6d:
        uVar5 = FUN_004c51f0(pvVar4,local_10c);
        return uVar5;
      }
      _DAT_006b66e8 = 0xc;
    }
    else {
      pvVar4 = param_2;
      if ((int)uVar3 <= (int)param_3) goto LAB_004cca6d;
      _DAT_006b66e8 = 0x22;
    }
  }
  return 0;
}

