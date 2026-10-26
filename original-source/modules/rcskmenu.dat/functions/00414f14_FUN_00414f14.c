/*
 * FUN_00414f14 at 00414f14
 * undefined4 __register FUN_00414f14(void)
 * Address ranges: 00414f14-00414f53
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00414f14(void)

{
  char cVar1;
  undefined4 uVar2;
  int *in_stack_00000004;
  int *in_stack_00000008;
  int *in_stack_0000000c;
  
  if (in_stack_00000004[7] == 0) {
    cVar1 = FUN_00402f40(in_stack_00000004,in_stack_00000008,in_stack_0000000c);
    if (cVar1 == '\0') {
      uVar2 = 0x80004002;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = (*(code *)**(undefined4 **)in_stack_00000004[7])();
  }
  return uVar2;
}

