/*
 * FUN_0043dd94 at 0043dd94
 * undefined1 __register FUN_0043dd94(void)
 * Address ranges: 0043dd94-0043de03
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 FUN_0043dd94(void)

{
  char cVar1;
  undefined1 uVar2;
  int in_stack_00000004;
  
  uVar2 = *(int *)(DAT_0047d7bc + 4) != 0;
  if ((*(char *)(in_stack_00000004 + -1) != '\0') && (DAT_0047d7d8 == '\x02')) {
    cVar1 = (**(code **)(*DAT_0047d7b8 + 0x50))();
    if ((cVar1 == '\0') && (DAT_0047d7b8[0x24] != 0)) {
      if ((int *)DAT_0047d7b8[0x24] != (int *)0x0) {
        uVar2 = FUN_00403088((int *)DAT_0047d7b8[0x24],*(undefined4 *)(DAT_0047d7bc + 4),
                             DAT_0047d7b8);
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

