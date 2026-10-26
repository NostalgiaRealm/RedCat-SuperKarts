/*
 * FUN_00472a50 at 00472a50
 * undefined FUN_00472a50(void)
 * Address ranges: 00472a50-00472cd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472a50(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  int iStack00000004;
  uint uStack00000008;
  uint uStack0000000c;
  int iStack0000001c;
  int in_stack_00000020;
  ushort in_stack_00002338;
  undefined2 in_stack_0000233a;
  char in_stack_0000233c;
  byte in_stack_0000233d;
  
  FUN_004c0200();
  if (0x500 < in_stack_00002338) {
    FUN_004afee0();
  }
  uVar4 = 0xffffffff;
  if ((in_stack_0000233d & 0x20) == 0) {
    iStack0000001c = -1;
    uStack00000008 = 0xffffffff;
    uVar5 = (CONCAT12(in_stack_0000233c,in_stack_0000233a) & 0xffff) - 1;
  }
  else {
    uVar5 = 0;
    uStack00000008 = CONCAT12(in_stack_0000233c,in_stack_0000233a) & 0xffff;
    iStack0000001c = 1;
  }
  if ((in_stack_0000233d & 0x10) == 0) {
    uStack0000000c = 0;
    uVar4 = (uint)in_stack_00002338;
    iStack00000004 = 1;
  }
  else {
    iStack00000004 = -1;
    uStack0000000c = in_stack_00002338 - 1;
  }
  FUN_004b08e0();
  iVar2 = FUN_004b0770();
  if (in_stack_0000233c == '\x18') {
    for (; uVar5 != uStack00000008; uVar5 = uVar5 + iStack0000001c) {
      puVar6 = (undefined2 *)(uVar5 * in_stack_00000020 + iVar2);
      FUN_004bf930();
      for (uVar3 = uStack0000000c; uVar3 != uVar4; uVar3 = uVar3 + iStack00000004) {
        uVar1 = FUN_004b5470();
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
      }
    }
  }
  else if (in_stack_0000233c == ' ') {
    for (; uVar5 != uStack00000008; uVar5 = uVar5 + iStack0000001c) {
      puVar6 = (undefined2 *)(uVar5 * in_stack_00000020 + iVar2);
      FUN_004bf930();
      for (uVar3 = uStack0000000c; uVar3 != uVar4; uVar3 = uVar3 + iStack00000004) {
        uVar1 = FUN_004b5470();
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
      }
    }
  }
  FUN_004b08a0();
  return;
}

