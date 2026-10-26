/*
 * FUN_004615d8 at 004615d8
 * int * __register FUN_004615d8(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 004615d8-0046167a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_004615d8(int *param_1,char param_2,undefined4 param_3)

{
  undefined4 extraout_ECX;
  char extraout_DL;
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  
  cVar1 = '\0';
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe4,in_stack_ffffffe8);
    param_3 = extraout_ECX;
    cVar1 = extraout_DL;
  }
  FUN_0045d414(param_1,'\0',param_3);
  FUN_00403ba4(param_1 + 0xb4,(undefined4 *)"PHASE_CONTROL_SETTINGS");
  *(undefined1 *)((int)param_1 + 0x34d) = 0;
  *(undefined1 *)((int)param_1 + 0x34e) = 0;
  *(undefined1 *)((int)param_1 + 0x34f) = 0;
  param_1[0xd4] = 0;
  DAT_0047e1dc = (undefined1)param_1[0xd4];
  *(undefined1 *)(param_1 + 0xd3) = DAT_0047e1dc;
  (**(code **)(*(int *)param_1[0xd0] + 0xb8))
            ((int *)param_1[0xd0],*(undefined1 *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c) + 0x18))
  ;
  FUN_004616f0((int)param_1);
  FUN_00461b20((int)param_1);
  if (cVar1 != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

