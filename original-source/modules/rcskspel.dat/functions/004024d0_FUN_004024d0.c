/*
 * FUN_004024d0 at 004024d0
 * undefined FUN_004024d0(void)
 * Address ranges: 004024d0-00402596
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004024d0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = (int)param_1;
  iVar3 = 0;
  if (((int)param_1 < DAT_00508610) || ((&DAT_00503ef4)[(int)param_1 * 0x47] != 9)) {
    FUN_0043b790((&DAT_00503ef0)[(int)param_1 * 0x47],1);
  }
  else {
    FUN_0049dd20(*(undefined4 *)((&DAT_00503ef0)[(int)param_1 * 0x47] * 0xd0 + 0x18 + DAT_0067ee20))
    ;
    FUN_0049d7a0();
  }
  if ((int)param_1 < DAT_00508610) {
    param_1 = &DAT_00503cc0;
    piVar4 = param_1;
  }
  else {
    param_1 = &DAT_00503a90;
    piVar4 = param_1;
    if (DAT_0053b9e8 != 0) {
      FUN_00412ca0();
    }
  }
  while ((*piVar4 != (&DAT_00503ef4)[iVar1 * 0x47] ||
         (iVar2 = (*(code *)piVar4[3])(iVar1), piVar4[2] != iVar2))) {
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 4;
    if (0x22 < iVar3) {
      return;
    }
  }
  (&DAT_00503ef4)[iVar1 * 0x47] = param_1[iVar3 * 4 + 1];
  return;
}

