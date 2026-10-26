/*
 * FUN_00412550 at 00412550
 * undefined __register FUN_00412550(int param_1, char * param_2)
 * Address ranges: 00412550-00412583
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412550(int param_1,char *param_2)

{
  undefined4 uVar1;
  code *in_stack_0000000c;
  undefined4 in_stack_00000010;
  
  uVar1 = FUN_00407d58(param_2,*(char **)(param_1 + 0x70));
  if (((char)uVar1 != '\0') && (in_stack_0000000c._2_2_ != 0)) {
    (*in_stack_0000000c)(in_stack_00000010,param_1);
    FUN_00403b50((int *)(param_1 + 0x70));
  }
  return;
}

