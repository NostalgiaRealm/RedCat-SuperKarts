/*
 * FUN_00404104 at 00404104
 * undefined __register FUN_00404104(int * param_1, uint param_2)
 * Address ranges: 00404104-00404165
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00404104(int *param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iStack_10;
  
  puVar3 = (undefined4 *)0x0;
  if (param_2 != 0) {
    iStack_10 = *param_1;
    if ((iStack_10 != 0) && (*(int *)(iStack_10 + -8) == 1)) {
      iStack_10 = iStack_10 + -8;
      FUN_00402744(&iStack_10,param_2 + 9);
      *param_1 = iStack_10 + 8;
      *(uint *)(iStack_10 + 4) = param_2;
      *(undefined1 *)(iStack_10 + 8 + param_2) = 0;
      return;
    }
    iStack_10 = 0x404141;
    puVar3 = FUN_00403c14(param_2);
    puVar1 = (undefined4 *)*param_1;
    if (puVar1 != (undefined4 *)0x0) {
      uVar2 = puVar1[-1];
      if ((int)param_2 <= (int)puVar1[-1]) {
        uVar2 = param_2;
      }
      iStack_10 = 0x404159;
      FUN_0040282c(puVar1,puVar3,uVar2);
    }
  }
  iStack_10 = 0x404160;
  FUN_00403b50(param_1);
  *param_1 = (int)puVar3;
  return;
}

