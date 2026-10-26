/*
 * FUN_004695f0 at 004695f0
 * undefined __register FUN_004695f0(void)
 * Address ranges: 004695f0-004696d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004695f0(void)

{
  DWORD DVar1;
  uint uVar2;
  int in_stack_00000000;
  int *in_stack_00000004;
  char *in_stack_00000008;
  undefined4 local_34 [8];
  undefined1 *local_14;
  undefined1 *local_10;
  uint local_c;
  uint local_8;
  
  local_c = (uint)(byte)in_stack_00000008[1];
  for (uVar2 = local_c; uVar2 != 0; uVar2 = uVar2 - 1) {
  }
  local_14 = &stack0xffffffc0;
  local_8 = (uint)(byte)in_stack_00000008[2];
  for (uVar2 = local_8; uVar2 != 0; uVar2 = uVar2 - 1) {
  }
  if (*in_stack_00000008 == '\x04') {
    local_8 = local_8 + 1;
  }
  local_10 = &stack0xffffffc0;
  FUN_004695e0(local_34);
  DVar1 = (**(code **)(*in_stack_00000004 + 0x18))();
  if (DVar1 != 0) {
    FUN_00469500(DVar1,(int)local_34,in_stack_00000000,(char)in_stack_00000004);
    return;
  }
  return;
}

