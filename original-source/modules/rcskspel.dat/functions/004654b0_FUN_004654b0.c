/*
 * FUN_004654b0 at 004654b0
 * undefined FUN_004654b0(void)
 * Address ranges: 004654b0-00465519
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004654b0(int param_1)

{
  float10 fVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_004cf774;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x10) = 1;
  fVar1 = (float10)FUN_0048f4d0();
  *(float *)(param_1 + 0x1c) = (float)fVar1;
  FUN_00465880();
  FUN_00458460(1);
  FUN_00465570();
  ExceptionList = local_10;
  return;
}

