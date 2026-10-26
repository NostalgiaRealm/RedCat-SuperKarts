/*
 * FUN_00450500 at 00450500
 * undefined FUN_00450500(void)
 * Address ranges: 00450500-00450681
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00450500(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iStack00000004;
  int local_54;
  int local_50;
  
  local_50 = 0;
  local_54 = 1;
  iVar7 = 0;
  if (1 < DAT_00680b2c) {
    iStack00000004 = 0;
    iVar8 = -0x24 - DAT_00680b28;
    iVar9 = DAT_00680b28 + 0x9a8;
    do {
      uVar1 = __ftol();
      uVar2 = __ftol();
      uVar3 = __ftol();
      uVar4 = __ftol();
      uVar5 = __ftol();
      uVar6 = __ftol();
      if ((int)(((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f)) +
                ((uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f)) +
               ((uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f))) <
          (int)(((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f)) +
                ((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)) +
               ((uVar3 ^ (int)uVar3 >> 0x1f) - ((int)uVar3 >> 0x1f)))) {
        iStack00000004 = iVar8 + iVar9;
        local_50 = local_54;
      }
      local_54 = local_54 + 1;
      iVar9 = iVar9 + 0x984;
      iVar7 = local_50;
    } while (local_54 < DAT_00680b2c);
  }
  return iVar7;
}

