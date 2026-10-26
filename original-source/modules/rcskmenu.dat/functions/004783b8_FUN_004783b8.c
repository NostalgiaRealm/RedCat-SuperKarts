/*
 * FUN_004783b8 at 004783b8
 * undefined FUN_004783b8(void)
 * Address ranges: 004783b8-004784ed
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004783b8(int param_1)

{
  undefined1 uVar1;
  undefined4 extraout_EDX;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  uint *puStack_c;
  undefined1 uStack_6;
  undefined1 uStack_5;
  
  puStack_14 = &stack0xfffffffc;
  puStack_c = (uint *)0x0;
  puStack_18 = &LAB_004784ee;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  FUN_0047851c(param_1);
  FUN_00478798();
  FUN_00458490(*(int *)(*(int *)PTR_DAT_0047c670 + 0x90),(undefined2 *)&uStack_6,
               *(int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x14));
  *(undefined1 *)(param_1 + 0x390) = uStack_6;
  *(undefined1 *)(param_1 + 0x391) = uStack_5;
  uVar1 = FUN_0045a9e0(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80));
  *(undefined1 *)(param_1 + 0x392) = uVar1;
  FUN_0043f67c(*(int *)(param_1 + 0x2f4),
               *(uint **)(PTR_PTR_0047c908 + (uint)*(byte *)(param_1 + 0x390) * 4));
  FUN_0043f67c(*(int *)(param_1 + 0x2f8),
               *(uint **)(PTR_PTR_0047c8ec + (uint)*(byte *)(param_1 + 0x391) * 4));
  FUN_00478958(param_1);
  FUN_00478c38(param_1);
  FUN_0045bbac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c),1);
  FUN_00478e80(param_1,CONCAT31((int3)((uint)extraout_EDX >> 8),*(undefined1 *)(param_1 + 0x390)),
               (int *)&puStack_c);
  FUN_0043f67c(*(int *)(param_1 + 0x38c),puStack_c);
  FUN_00478ab4(param_1,(uint)*(byte *)(param_1 + 0x390));
  FUN_0045c720((&DAT_0047c5a4)
               [(uint)*(byte *)(param_1 + 0x391) + (uint)*(byte *)(param_1 + 0x390) * 5]);
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_004784f5;
  puStack_18 = (undefined1 *)0x4784ed;
  FUN_00403b50((int *)&puStack_c);
  return;
}

