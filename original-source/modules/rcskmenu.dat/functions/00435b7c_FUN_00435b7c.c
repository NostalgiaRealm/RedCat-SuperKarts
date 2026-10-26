/*
 * FUN_00435b7c at 00435b7c
 * undefined4 __register FUN_00435b7c(int * param_1, undefined * param_2)
 * Address ranges: 00435b7c-00435bd7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00435b7c(int *param_1,undefined *param_2)

{
  int iVar1;
  int iVar2;
  PCNZCH pCVar3;
  PCNZCH pCVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  iVar1 = FUN_00403dd0(*param_1);
  iVar2 = FUN_00403dd0((int)param_2);
  if (iVar2 <= iVar1) {
    iVar1 = FUN_00403dd0((int)param_2);
    pCVar3 = FUN_00403f94(param_2);
    pCVar4 = FUN_00403f94((undefined *)*param_1);
    iVar1 = FUN_00407e24(pCVar4,pCVar3,iVar1);
    if (iVar1 == 0) {
      uVar5 = 1;
      iVar1 = FUN_00403dd0((int)param_2);
      FUN_00404018(param_1,1,iVar1);
    }
  }
  return uVar5;
}

