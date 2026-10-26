/*
 * FUN_00468cb8 at 00468cb8
 * undefined __register FUN_00468cb8(int * param_1, char param_2, int param_3, int param_4, DWORD param_5)
 * Address ranges: 00468cb8-00468d5e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00468cb8(int *param_1,char param_2,int param_3,int param_4,DWORD param_5)

{
  int extraout_ECX;
  undefined1 extraout_DL;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar1;
  undefined4 uStack_40;
  undefined1 *puStack_3c;
  undefined1 *puStack_38;
  undefined4 in_stack_ffffffcc;
  undefined4 in_stack_ffffffd0;
  DWORD local_18;
  undefined1 local_14;
  byte *local_10;
  undefined4 *local_c;
  undefined1 local_5;
  
  local_10 = (byte *)0x0;
  local_c = (undefined4 *)0x0;
  local_5 = 0;
  if (param_2 != '\0') {
    puStack_38 = (undefined1 *)0x468cd5;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffcc,in_stack_ffffffd0);
    param_3 = extraout_ECX;
    local_5 = extraout_DL;
  }
  puStack_3c = &LAB_00468d5f;
  uStack_40 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_40;
  puStack_38 = &stack0xfffffffc;
  FUN_00403be8((int *)&local_c,param_3);
  if (local_c == (undefined4 *)0x0) {
    FUN_0040a478(param_5,(int *)&local_c);
    if (local_c == (undefined4 *)0x0) {
      uVar1 = 0;
      FUN_00405438((undefined4 *)PTR_PTR_0047c658,(int *)&local_10);
      local_18 = param_5;
      local_14 = 0;
      FUN_00408a70((int *)&local_c,local_10,&local_18,uVar1);
    }
  }
  FUN_0040adf0(param_1,'\0',local_c,param_4);
  param_1[3] = param_5;
  *in_FS_OFFSET = uStack_40;
  puStack_38 = &LAB_00468d66;
  puStack_3c = (undefined1 *)0x468d5e;
  FUN_00403b74((int *)&local_10,2);
  return;
}

