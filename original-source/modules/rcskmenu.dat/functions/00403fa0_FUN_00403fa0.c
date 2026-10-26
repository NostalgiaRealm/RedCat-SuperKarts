/*
 * FUN_00403fa0 at 00403fa0
 * int __register FUN_00403fa0(int * param_1)
 * Address ranges: 00403fa0-00403fd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00403fa0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if ((iVar3 != 0) && (*(int *)(iVar3 + -8) != 1)) {
    puVar2 = FUN_00403c14(*(int *)(iVar3 + -4));
    puVar1 = (undefined4 *)*param_1;
    *param_1 = (int)puVar2;
    if (0 < (int)puVar1[-2]) {
      LOCK();
      puVar1[-2] = puVar1[-2] + -1;
      UNLOCK();
    }
    FUN_0040282c(puVar1,puVar2,puVar1[-1]);
    iVar3 = *param_1;
  }
  return iVar3;
}

