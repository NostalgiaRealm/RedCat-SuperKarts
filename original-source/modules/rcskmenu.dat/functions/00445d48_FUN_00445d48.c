/*
 * FUN_00445d48 at 00445d48
 * undefined __register FUN_00445d48(int * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5)
 * Address ranges: 00445d48-00445dc4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445d48(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5)

{
  int iVar1;
  
  iVar1 = param_1[0x19];
  if (*(int *)(iVar1 + 0x14) == 0) {
    *param_2 = 0;
  }
  else {
    *param_2 = *(undefined4 *)(param_1[0x19] + 0x14);
  }
  if (*(int *)(iVar1 + 0x10) == 0) {
    *param_3 = 0;
  }
  else {
    *param_3 = *(undefined4 *)(param_1[0x19] + 0x10);
  }
  if (*(int *)(iVar1 + 0xc) == 0) {
    *param_5 = 0;
  }
  else {
    *param_5 = *(undefined4 *)(param_1[0x19] + 0xc);
  }
  if (*(int *)(iVar1 + 8) == 0) {
    *param_4 = 0;
  }
  else {
    *param_4 = *(undefined4 *)(param_1[0x19] + 8);
  }
  (**(code **)(*param_1 + 0x38))();
  return;
}

