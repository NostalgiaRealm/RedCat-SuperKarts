/*
 * FUN_0041a2e8 at 0041a2e8
 * undefined __register FUN_0041a2e8(int * param_1, char param_2)
 * Address ranges: 0041a2e8-0041a3c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041a2e8(int *param_1,char param_2)

{
  undefined4 uVar1;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined **ppuVar2;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 in_stack_ffffffd4;
  undefined4 in_stack_ffffffd8;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  uVar1 = 0;
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  if (param_2 != '\0') {
    puStack_30 = (undefined1 *)0x41a2ff;
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,0,in_stack_ffffffd4,in_stack_ffffffd8);
    uVar1 = extraout_ECX;
  }
  puStack_34 = &LAB_0041a3c5;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_30 = &stack0xfffffffc;
  FUN_00402e7c(param_1,'\0',uVar1);
  uVar1 = 0;
  ppuVar2 = &PTR_FUN_004166f0;
  FUN_00405438((undefined4 *)PTR_PTR_0047c7f8,(int *)&local_8);
  FUN_0041a468(param_1,&DAT_0041a3f4,local_8,ppuVar2,uVar1);
  uVar1 = 0;
  ppuVar2 = &PTR_FUN_004166f0;
  FUN_00405438((undefined4 *)PTR_PTR_0047c660,(int *)&local_c);
  FUN_0041a468(param_1,&DAT_0041a400,local_c,ppuVar2,uVar1);
  uVar1 = 0;
  ppuVar2 = &PTR_FUN_004169a0;
  FUN_00405438((undefined4 *)PTR_PTR_0047c65c,(int *)&local_10);
  FUN_0041a468(param_1,&DAT_0041a40c,local_10,ppuVar2,uVar1);
  uVar1 = 0;
  ppuVar2 = &PTR_FUN_00416860;
  FUN_00405438((undefined4 *)PTR_PTR_0047c654,(int *)&local_14);
  FUN_0041a468(param_1,&LAB_0041a418,local_14,ppuVar2,uVar1);
  *in_FS_OFFSET = ppuVar2;
  FUN_00403b74((int *)&local_14,4);
  return;
}

