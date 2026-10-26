/*
 * FUN_004153f0 at 004153f0
 * undefined FUN_004153f0(void)
 * Address ranges: 004153f0-0041558b;004155ae-004155c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004153f0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *in_FS_OFFSET;
  bool bVar5;
  int in_stack_00000004;
  int *in_stack_00000008;
  uint in_stack_0000000c;
  int in_stack_00000010;
  uint *in_stack_00000014;
  undefined4 *in_stack_00000018;
  undefined4 uStack_5c;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  undefined4 uStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  undefined4 uStack_44;
  undefined1 *puStack_40;
  undefined1 *puStack_3c;
  uint uStack_1c;
  uint uStack_18;
  uint uStack_10;
  int iStack_8;
  
  puStack_3c = (undefined1 *)0x415401;
  FUN_004054c4(in_stack_00000008);
  puStack_40 = &LAB_004155c4;
  uStack_44 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_44;
  uStack_1c = 0;
  uStack_18 = 0;
  puStack_4c = &LAB_0041559d;
  uStack_50 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_50;
  if (in_stack_00000010 == 0) {
    if (in_stack_0000000c < 0x100001) {
LAB_0041545a:
      uStack_10 = in_stack_0000000c;
      goto LAB_00415460;
    }
  }
  else if (in_stack_00000010 < 1) goto LAB_0041545a;
  uStack_10 = 0x100000;
LAB_00415460:
  puStack_54 = (undefined1 *)0x415468;
  puStack_48 = &stack0xfffffffc;
  puStack_3c = &stack0xfffffffc;
  iVar2 = FUN_00402714(uStack_10);
  puStack_58 = &LAB_0041558c;
  uStack_5c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_5c;
  puStack_54 = &stack0xfffffffc;
  do {
    if (in_stack_00000010 == 0) {
      if (in_stack_0000000c == 0) {
LAB_0041554c:
        *in_FS_OFFSET = uStack_5c;
        puStack_54 = &DAT_00415593;
        puStack_58 = (undefined1 *)0x415561;
        FUN_0040272c(iVar2);
        if (in_stack_00000018 != (undefined4 *)0x0) {
          *in_stack_00000018 = 0;
          in_stack_00000018[1] = 0;
        }
        if (in_stack_00000014 != (uint *)0x0) {
          *in_stack_00000014 = uStack_1c;
          in_stack_00000014[1] = uStack_18;
        }
        return;
      }
    }
    else if (in_stack_00000010 < 1) goto LAB_0041554c;
    uVar1 = in_stack_0000000c;
    if (in_stack_00000010 == 0) {
      if (0x7fffffff < in_stack_0000000c) {
LAB_00415491:
        uVar1 = 0x7fffffff;
      }
    }
    else if (0 < in_stack_00000010) goto LAB_00415491;
    for (; 0 < (int)uVar1; uVar1 = uVar1 - uVar4) {
      uVar4 = uVar1;
      if ((int)uStack_10 < (int)uVar1) {
        uVar4 = uStack_10;
      }
      uVar3 = (**(code **)(**(int **)(in_stack_00000004 + 0xc) + 4))
                        (*(int **)(in_stack_00000004 + 0xc),iVar2,uVar4);
      bVar5 = CARRY4(uStack_1c,uVar3);
      uStack_1c = uStack_1c + uVar3;
      uStack_18 = uStack_18 + ((int)uVar3 >> 0x1f) + (uint)bVar5;
      iStack_8 = (**(code **)(*in_stack_00000008 + 0x10))();
      if ((iStack_8 == 0) && (uVar4 != 0)) {
        iStack_8 = -0x7fffbffb;
      }
      if (iStack_8 != 0) {
        FUN_004036a4();
        *in_FS_OFFSET = uStack_50;
        *in_FS_OFFSET = uStack_44;
        puStack_3c = &LAB_004155cb;
        puStack_40 = (undefined1 *)0x4155c3;
        FUN_00405490((int *)&stack0x00000008);
        return;
      }
    }
    bVar5 = in_stack_0000000c < uVar1;
    in_stack_0000000c = in_stack_0000000c - uVar1;
    in_stack_00000010 = (in_stack_00000010 - ((int)uVar1 >> 0x1f)) - (uint)bVar5;
  } while( true );
}

