/*
 * FUN_0043c7ac at 0043c7ac
 * undefined4 __register FUN_0043c7ac(void)
 * Address ranges: 0043c7ac-0043c863
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0043c7ac(void)

{
  HANDLE pvVar1;
  uint uVar2;
  LONG LVar3;
  undefined4 uVar4;
  HWND in_stack_00000004;
  
  *(HWND *)((int)DAT_0047b8f8 + 0x14c) = in_stack_00000004;
  SetWindowLongA(in_stack_00000004,-4,*(LONG *)((int)DAT_0047b8f8 + 0x15c));
  uVar2 = GetWindowLongA(in_stack_00000004,-0x10);
  if ((uVar2 & 0x40000000) != 0) {
    LVar3 = GetWindowLongA(in_stack_00000004,-0xc);
    if (LVar3 == 0) {
      SetWindowLongA(in_stack_00000004,-0xc,(LONG)in_stack_00000004);
    }
  }
  SetPropA(in_stack_00000004,(LPCSTR)(uint)DAT_0047d7b6,DAT_0047b8f8);
  SetPropA(in_stack_00000004,(LPCSTR)(uint)DAT_0047d7b4,DAT_0047b8f8);
  pvVar1 = DAT_0047b8f8;
  DAT_0047b8f8 = (HANDLE)0x0;
  uVar4 = (**(code **)((int)pvVar1 + 0x15c))();
  return uVar4;
}

