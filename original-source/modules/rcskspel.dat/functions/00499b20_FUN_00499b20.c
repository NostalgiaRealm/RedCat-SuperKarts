/*
 * FUN_00499b20 at 00499b20
 * undefined FUN_00499b20(void)
 * Address ranges: 00499b20-00499c26
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00499b20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_8;
  
  iVar4 = param_1 * 0xd0;
  iVar3 = *(int *)(DAT_0067ee20 + 0x1c + iVar4);
  if (*(int *)(DAT_0067ee20 + 0x48 + iVar4) == 0) {
    local_8 = -1;
    do {
      iVar1 = FUN_00493a20(local_8 + iVar3);
      iVar6 = 0;
      iVar2 = *(int *)(DAT_00680b28 + 0xe0 + iVar1 * 0x984);
      if (0 < iVar2) {
        do {
          FUN_004997f0(iVar1,iVar6);
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar2);
      }
      local_8 = local_8 + 1;
    } while (local_8 < 2);
  }
  piVar5 = &DAT_0067ee7c;
  iVar3 = DAT_0067ee20;
  do {
    if ((((piVar5[-1] != 0) && (*piVar5 != param_1)) &&
        (iVar2 = FUN_00493a40(*(undefined4 *)(iVar3 + 0x1c + iVar4),
                              *(undefined4 *)(*piVar5 * 0xd0 + 0x1c + iVar3)), iVar3 = DAT_0067ee20,
        iVar2 < 10)) &&
       (((iVar2 = *piVar5, iVar2 != *(int *)(DAT_0067ee20 + 0x2c + iVar4) &&
         (iVar2 != *(int *)(DAT_0067ee20 + 0x30 + iVar4))) &&
        ((*(byte *)(iVar2 * 0xd0 + 4 + DAT_0067ee20) & 8) == 0)))) {
      FUN_00499630(iVar2);
      iVar3 = DAT_0067ee20;
    }
    piVar5 = piVar5 + 2;
  } while ((int)piVar5 < 0x67fe1c);
  return;
}

