/*
 * FUN_0046af90 at 0046af90
 * undefined __register FUN_0046af90(int param_1)
 * Address ranges: 0046af90-0046b145
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046af90(int param_1)

{
  undefined *puVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  uint *local_c;
  uint *local_8;
  
  puVar1 = PTR_DAT_0047c670;
  puStack_18 = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (uint *)0x0;
  puStack_1c = &LAB_0046b146;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  cVar2 = FUN_0045bb50(*(int *)(*(int *)puVar1 + 0x7c));
  (**(code **)(**(int **)(param_1 + 0x328) + 0xb8))(*(int **)(param_1 + 0x328),cVar2 == '\0');
  cVar2 = FUN_0045bb50(*(int *)(*(int *)puVar1 + 0x7c));
  (**(code **)(**(int **)(param_1 + 0x32c) + 0xb8))(*(int **)(param_1 + 0x32c),cVar2 == '\x02');
  cVar2 = FUN_0045bb50(*(int *)(*(int *)puVar1 + 0x7c));
  (**(code **)(**(int **)(param_1 + 0x330) + 0xb8))(*(int **)(param_1 + 0x330),cVar2 == '\x01');
  cVar2 = (**(code **)(**(int **)(param_1 + 0x328) + 0xb4))();
  (**(code **)(**(int **)(param_1 + 0x334) + 0x5c))(*(int **)(param_1 + 0x334),cVar2 == '\x01');
  if ((*(char *)(param_1 + 0x366) == '\0') || (*(char *)(param_1 + 0x366) == '\x03')) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  (**(code **)(**(int **)(param_1 + 0x318) + 0xb8))(*(int **)(param_1 + 0x318),uVar5);
  if ((*(char *)(param_1 + 0x366) == '\x01') || (*(char *)(param_1 + 0x366) == '\x04')) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  (**(code **)(**(int **)(param_1 + 0x31c) + 0xb8))(*(int **)(param_1 + 0x31c),uVar5);
  (**(code **)(**(int **)(param_1 + 0x358) + 0xb8))
            (*(int **)(param_1 + 0x358),*(char *)(*(int *)(*(int *)puVar1 + 0x7c) + 0x18) == '\x01')
  ;
  (**(code **)(**(int **)(param_1 + 0x344) + 0xb8))
            (*(int **)(param_1 + 0x344),*(char *)(param_1 + 0x365) == '\x01');
  iVar4 = FUN_0045bb88(*(int *)(*(int *)puVar1 + 0x7c));
  FUN_0045fd98(*(int **)(param_1 + 0x2f0),iVar4);
  iVar4 = FUN_0045bb68(*(int *)(*(int *)puVar1 + 0x7c));
  FUN_0045fd98(*(int **)(param_1 + 0x2f8),iVar4);
  FUN_0046b8dc(param_1,*(int *)(PTR_PTR_0047c934 + (uint)*(byte *)(param_1 + 0x366) * 4),&local_8);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x348) + 300),local_8);
  bVar3 = FUN_0045bb50(*(int *)(*(int *)puVar1 + 0x7c));
  FUN_0046b8dc(param_1,*(int *)(PTR_PTR_0047c99c + (bVar3 & 0x7f) * 4),&local_c);
  FUN_00452c0c(*(int *)(*(int *)(param_1 + 0x34c) + 300),local_c);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0046b14d;
  puStack_1c = (undefined1 *)0x46b145;
  FUN_00403b74((int *)&local_c,2);
  return;
}

