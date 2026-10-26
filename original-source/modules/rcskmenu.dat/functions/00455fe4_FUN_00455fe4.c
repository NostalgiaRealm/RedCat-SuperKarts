/*
 * FUN_00455fe4 at 00455fe4
 * undefined __register FUN_00455fe4(int param_1, int * param_2, int param_3)
 * Address ranges: 00455fe4-00456052
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00455fe4(int param_1,int *param_2,int param_3)

{
  undefined1 in_ZF;
  int local_c;
  
  local_c = param_3;
  FUN_00402744((int *)(param_1 + 0x28),*(int *)(param_1 + 0x2c));
  FUN_004118e8(param_2,*(undefined4 *)(param_1 + 0x28),*(int *)(param_1 + 0x2c));
  local_c = **(int **)(param_1 + 0x28);
  FUN_00402ae4(&local_c,(int *)&DAT_0047bd30,4);
  if (!(bool)in_ZF) {
    FUN_00403b34("Geen geldig wave bestand.");
  }
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x28) + 0x14;
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x28);
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x28) + 0x2c;
  return;
}

