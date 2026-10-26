/*
 * FUN_0043f740 at 0043f740
 * undefined FUN_0043f740(void)
 * Address ranges: 0043f740-0043f9cd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0043f740(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puStack_c;
  
  FUN_0043f490(param_1);
  FUN_004bfd5a();
  iVar2 = __ftol();
  if (((float)iVar2 <= _DAT_0053ba8c) || (1024.0 - _DAT_0053ba8c <= (float)iVar2)) {
    uVar3 = __ftol();
    uVar4 = __ftol();
    if ((int)(((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f)) +
             ((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f))) < 0x46) {
      uVar5 = DAT_0053be28;
      FUN_0048e210(DAT_0053be28);
      FUN_0048e780(uVar5);
    }
    param_1 = 0;
    if (0 < DAT_00508610) {
      puStack_c = &DAT_005081bc;
      do {
        FUN_00417e90(param_1);
        uVar3 = __ftol();
        FUN_00417e90(param_1);
        uVar4 = __ftol();
        if ((int)(((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f)) +
                 ((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f))) < 0x46) {
          cVar1 = FUN_00417e90(param_1);
          uVar5 = DAT_0053be28;
          if (cVar1 == '\0') {
            uVar5 = *puStack_c;
          }
          FUN_0048e210(uVar5);
          FUN_0048e780(uVar5);
        }
        param_1 = param_1 + 1;
        puStack_c = puStack_c + 0x1c;
      } while (param_1 < DAT_00508610);
    }
  }
  FUN_004a09e0();
  return 1;
}

