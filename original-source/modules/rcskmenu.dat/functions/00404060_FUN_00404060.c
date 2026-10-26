/*
 * FUN_00404060 at 00404060
 * undefined __register FUN_00404060(undefined4 * param_1, int * param_2, int param_3)
 * Address ranges: 00404060-004040ba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404060(undefined4 *param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_2;
    iVar3 = 0;
    if (puVar1 != (undefined4 *)0x0) {
      iVar3 = puVar1[-1];
    }
    iVar4 = param_3 + -1;
    if (param_3 < 1) {
      iVar4 = 0;
    }
    if (iVar3 < iVar4) {
      iVar4 = iVar3;
    }
    uVar2 = param_1[-1];
    FUN_00404104(param_2,iVar3 + uVar2);
    if (puVar1 == param_1) {
      param_1 = (undefined4 *)*param_2;
    }
    iVar3 = *param_2;
    FUN_0040282c((undefined4 *)(iVar3 + iVar4),(undefined4 *)(iVar4 + uVar2 + iVar3),
                 *(int *)(iVar3 + -4) - (iVar4 + uVar2));
    FUN_0040282c(param_1,(undefined4 *)(*param_2 + iVar4),uVar2);
  }
  return;
}

