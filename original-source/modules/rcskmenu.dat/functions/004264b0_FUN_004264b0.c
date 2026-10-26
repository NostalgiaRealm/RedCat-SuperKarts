/*
 * FUN_004264b0 at 004264b0
 * undefined FUN_004264b0(void)
 * Address ranges: 004264b0-00426504
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004264b0(int param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  LRESULT LVar4;
  uint extraout_ECX;
  
  if ((((*(int **)(param_1 + 0x4c) == (int *)0x0) ||
       (cVar1 = FUN_00403088(*(int **)(param_1 + 0x4c),param_1,param_3), param_3 = extraout_ECX,
       cVar1 == '\0')) &&
      (uVar2 = FUN_004334cc(*(int *)PTR_DAT_0047c86c,param_1,param_3), (char)uVar2 == '\0')) &&
     ((uVar3 = FUN_004150f4(param_1), (char)uVar3 == '\0' &&
      (LVar4 = FUN_0043c880(0xb03f,0,param_1), LVar4 != 1)))) {
    return 0;
  }
  return 1;
}

