/*
 * FUN_00468d88 at 00468d88
 * undefined __register FUN_00468d88(int * param_1, char param_2, undefined4 * param_3, int param_4, undefined4 * param_5, undefined4 * param_6, DWORD param_7)
 * Address ranges: 00468d88-00468df9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00468d88(int *param_1,char param_2,undefined4 *param_3,int param_4,undefined4 *param_5,
                 undefined4 *param_6,DWORD param_7)

{
  undefined4 *extraout_ECX;
  int *in_FS_OFFSET;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 in_stack_ffffffdc;
  undefined4 in_stack_ffffffe0;
  int local_8;
  
  local_8 = 0;
  if (param_2 != '\0') {
    puStack_28 = (undefined1 *)0x468d9c;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffdc,in_stack_ffffffe0);
    param_3 = extraout_ECX;
  }
  puStack_2c = &LAB_00468dfa;
  puStack_30 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = (int)&puStack_30;
  puStack_28 = &stack0xfffffffc;
  FUN_00468c68(param_3,&local_8);
  FUN_00468cb8(param_1,'\0',local_8,param_4,param_7);
  FUN_00403ba4(param_1 + 4,param_6);
  FUN_00403ba4(param_1 + 5,param_5);
  *in_FS_OFFSET = param_4;
  puStack_30 = &LAB_00468e01;
  FUN_00403b50(&local_8);
  return;
}

