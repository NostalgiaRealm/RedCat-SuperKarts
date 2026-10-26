/*
 * FUN_00412584 at 00412584
 * undefined __register FUN_00412584(int param_1, char * param_2)
 * Address ranges: 00412584-00412643;00412656-0041265c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412584(int param_1,char *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  code *in_stack_0000000c;
  undefined4 in_stack_00000010;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  uint local_10;
  int *local_c;
  int local_8;
  
  puStack_18 = (undefined1 *)0x41259d;
  local_8 = param_1;
  uVar1 = FUN_00407d58(param_2,*(char **)(param_1 + 0x70));
  if (((char)uVar1 != '\0') && (in_stack_0000000c._2_2_ != 0)) {
    puStack_18 = (undefined1 *)0x4125b8;
    uVar2 = FUN_004140d0(local_8,extraout_EDX,extraout_ECX);
    uVar3 = extraout_ECX_00;
    if ((char)uVar2 != '\n') {
      *(int *)(local_8 + 0x10) = *(int *)(local_8 + 0x10) + -1;
      puStack_18 = (undefined1 *)0x4125ca;
      FUN_00414230(local_8,extraout_EDX_00,extraout_ECX_00);
      *(undefined1 *)(local_8 + 0x74) = 1;
      puStack_18 = (undefined1 *)0x4125d6;
      FUN_004124c0();
      uVar3 = extraout_ECX_01;
    }
    puStack_18 = (undefined1 *)0x4125e2;
    local_c = (int *)FUN_00402e7c((int *)&PTR_FUN_0040e594,'\x01',uVar3);
    puStack_1c = &LAB_00412644;
    uStack_20 = *in_FS_OFFSET;
    *in_FS_OFFSET = &uStack_20;
    puStack_18 = &stack0xfffffffc;
    FUN_0041292c(local_8,&local_10,4);
    (**(code **)*local_c)(local_c,local_10);
    FUN_0041292c(local_8,(undefined4 *)local_c[1],local_10);
    *(undefined1 *)(local_8 + 0x74) = 1;
    (*in_stack_0000000c)(in_stack_00000010,local_c);
    *in_FS_OFFSET = uStack_20;
    puStack_18 = &DAT_0041264b;
    puStack_1c = (undefined1 *)0x412643;
    FUN_00402eac(local_c);
    return;
  }
  return;
}

