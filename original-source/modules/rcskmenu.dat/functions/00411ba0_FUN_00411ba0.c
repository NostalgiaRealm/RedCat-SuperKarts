/*
 * FUN_00411ba0 at 00411ba0
 * uint __register FUN_00411ba0(int param_1, undefined4 * param_2, uint param_3)
 * Address ranges: 00411ba0-00411bd7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00411ba0(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (((iVar1 < 0) || ((int)param_3 < 0)) || (uVar2 = *(int *)(param_1 + 8) - iVar1, (int)uVar2 < 1)
     ) {
    uVar2 = 0;
  }
  else {
    if ((int)param_3 < (int)uVar2) {
      uVar2 = param_3;
    }
    FUN_0040282c((undefined4 *)(*(int *)(param_1 + 4) + iVar1),param_2,uVar2);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar2;
  }
  return uVar2;
}

