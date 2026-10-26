/*
 * FUN_0044b778 at 0044b778
 * int * __register FUN_0044b778(int * param_1, char param_2, int * param_3)
 * Address ranges: 0044b778-0044b80b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0044b778(int *param_1,char param_2,int *param_3)

{
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe8;
  undefined4 in_stack_ffffffec;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe8,in_stack_ffffffec);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  FUN_00447088(param_1,'\0',param_3);
  param_1[0x10] = 0x8eb;
  FUN_0043eeb0(param_1,0xb9);
  FUN_0043eed0(param_1,0x29);
  *(undefined1 *)((int)param_1 + 0x207) = 2;
  FUN_0044bb84(param_1,2);
  FUN_0044bba0(param_1,1);
  *(undefined1 *)(param_1 + 0x81) = 0;
  FUN_0043f7d8((int)param_1,-0x7ffffff1);
  *(undefined1 *)((int)param_1 + 0x205) = 1;
  FUN_004459b0(param_1,1,extraout_ECX_00);
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe8;
  }
  return param_1;
}

