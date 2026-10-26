/*
 * FUN_0043f9ec at 0043f9ec
 * undefined1 __register FUN_0043f9ec(void)
 * Address ranges: 0043f9ec-0043fa76
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0043f9ec(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  BOOL BVar4;
  int in_stack_00000004;
  RECT local_28;
  tagRECT local_18;
  undefined1 local_5;
  
  local_5 = 1;
  puVar1 = *(undefined4 **)(*(int *)(*(int *)(in_stack_00000004 + -4) + 0x24) + 0x134);
  iVar2 = FUN_0040f70c((int)puVar1,*(int *)(in_stack_00000004 + -4));
  do {
    do {
      if (iVar2 < 1) {
        return 0;
      }
      iVar2 = iVar2 + -1;
      iVar3 = FUN_0040f6b0(puVar1,iVar2);
    } while ((*(char *)(iVar3 + 0x47) == '\0') || ((*(byte *)(iVar3 + 0x40) & 0x40) == 0));
    FUN_0043f054(iVar3,&local_28.left);
    IntersectRect(&local_18,(RECT *)(in_stack_00000004 + -0x14),&local_28);
    BVar4 = EqualRect(&local_18,(RECT *)(in_stack_00000004 + -0x14));
  } while (BVar4 == 0);
  return local_5;
}

