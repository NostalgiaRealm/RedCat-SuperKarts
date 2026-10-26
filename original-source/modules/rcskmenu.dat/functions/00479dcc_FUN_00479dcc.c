/*
 * FUN_00479dcc at 00479dcc
 * undefined __register FUN_00479dcc(void)
 * Address ranges: 00479dcc-00479e1b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00479dcc(void)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if ((cVar1 != '\x05') &&
     (cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c)), cVar1 != '\0')) {
    return;
  }
  piVar2 = FUN_0045d414((int *)&PTR_FUN_004797b4,'\x01',*(undefined4 *)PTR_DAT_0047c86c);
  (**(code **)(*piVar2 + 0xd8))();
  FUN_0042ed64(piVar2);
  return;
}

