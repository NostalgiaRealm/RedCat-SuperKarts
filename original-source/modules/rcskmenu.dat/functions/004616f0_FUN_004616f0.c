/*
 * FUN_004616f0 at 004616f0
 * undefined __register FUN_004616f0(int param_1)
 * Address ranges: 004616f0-0046184a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004616f0(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint *unaff_EBX;
  undefined4 *in_FS_OFFSET;
  uint *local_34;
  uint *local_30;
  uint *local_2c;
  uint *local_28;
  uint *local_24;
  uint *local_20;
  uint *local_1c;
  uint *local_18;
  uint *local_14;
  uint *local_c;
  uint *local_8;
  
  local_14 = (uint *)&stack0xfffffffc;
  iVar2 = 6;
  do {
    local_8 = (uint *)0x0;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  local_18 = (uint *)&LAB_0046184b;
  local_1c = (uint *)*in_FS_OFFSET;
  *in_FS_OFFSET = &local_1c;
  local_20 = (uint *)0x46171a;
  FUN_0045c4c8(2,(int *)&local_8);
  local_20 = (uint *)0x461728;
  FUN_0043f67c(*(int *)(param_1 + 0x2e4),local_8);
  local_20 = (uint *)0x461732;
  FUN_0045c4c8(0xe,(int *)&local_c);
  local_20 = (uint *)0x461740;
  FUN_0043f67c(*(int *)(param_1 + 0x2dc),local_c);
  local_20 = (uint *)0x46174a;
  FUN_0045c4c8(0xf,(int *)&stack0xfffffff0);
  local_20 = (uint *)0x461758;
  FUN_0043f67c(*(int *)(param_1 + 0x2e0),unaff_EBX);
  local_20 = (uint *)0x461762;
  FUN_0045c4c8(0x1a,(int *)&local_14);
  local_20 = (uint *)0x461770;
  FUN_0043f67c(*(int *)(param_1 + 0x2f8),local_14);
  local_20 = (uint *)0x46177a;
  FUN_0045c4c8(0x1b,(int *)&local_18);
  local_20 = (uint *)0x461788;
  FUN_0043f67c(*(int *)(param_1 + 0x2f0),local_18);
  local_20 = (uint *)0x461792;
  FUN_0045c4c8(0x1c,(int *)&local_1c);
  local_20 = (uint *)0x4617a0;
  FUN_0043f67c(*(int *)(param_1 + 0x2fc),local_1c);
  local_20 = (uint *)0x4617aa;
  FUN_0045c4c8(0x1d,(int *)&local_20);
  puVar1 = local_20;
  local_20 = (uint *)0x4617b8;
  FUN_0043f67c(*(int *)(param_1 + 0x2f4),puVar1);
  local_20 = (uint *)0x4617c2;
  FUN_0045c4c8(0x1e,(int *)&local_24);
  local_20 = (uint *)0x4617d0;
  FUN_0043f67c(*(int *)(param_1 + 0x2e8),local_24);
  local_20 = (uint *)0x4617da;
  FUN_0045c4c8(0x1f,(int *)&local_28);
  local_20 = (uint *)0x4617e8;
  FUN_0043f67c(*(int *)(param_1 + 0x2ec),local_28);
  local_20 = (uint *)0x4617f2;
  FUN_0045c4c8(0x21,(int *)&local_2c);
  local_20 = (uint *)0x461800;
  FUN_0043f67c(*(int *)(param_1 + 0x300),local_2c);
  local_20 = (uint *)0x46180a;
  FUN_0045c4c8(0x3e,(int *)&local_30);
  local_20 = (uint *)0x461818;
  FUN_0043f67c(*(int *)(param_1 + 0x344),local_30);
  local_20 = (uint *)0x461822;
  FUN_0045c4c8(0x4c,(int *)&local_34);
  local_20 = (uint *)0x461830;
  FUN_0043f67c(*(int *)(param_1 + 0x348),local_34);
  *in_FS_OFFSET = local_1c;
  local_14 = (uint *)&LAB_00461852;
  local_18 = (uint *)0x46184a;
  FUN_00403b74((int *)&local_34,0xc);
  return;
}

