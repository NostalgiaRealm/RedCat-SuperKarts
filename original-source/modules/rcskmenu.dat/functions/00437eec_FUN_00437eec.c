/*
 * FUN_00437eec at 00437eec
 * undefined __register FUN_00437eec(int * param_1, uint * param_2)
 * Address ranges: 00437eec-00437f13
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00437eec(int *param_1,uint *param_2)

{
  undefined1 in_ZF;
  
  FUN_00403ee0((uint *)param_1[9],param_2);
  if (!(bool)in_ZF) {
    FUN_00403ba4(param_1 + 9,param_2);
    (**(code **)(*param_1 + 0x38))(param_1,1);
  }
  return;
}

