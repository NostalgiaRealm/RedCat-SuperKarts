/*
 * FUN_00431fac at 00431fac
 * bool __register FUN_00431fac(int param_1, LPMSG param_2)
 * Address ranges: 00431fac-00431ff9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

bool FUN_00431fac(int param_1,LPMSG param_2)

{
  int iVar1;
  BOOL BVar2;
  bool bVar3;
  
  bVar3 = false;
  iVar1 = *(int *)(param_1 + 0x38);
  if ((((iVar1 != 0) && (*(char *)(iVar1 + 0x217) == '\x02')) &&
      (*(int *)(DAT_0047d774 + 0x60) != 0)) &&
     (*(char *)(*(int *)(DAT_0047d774 + 0x60) + 0x217) == '\x01')) {
    BVar2 = TranslateMDISysAccel(*(HWND *)(iVar1 + 0x23c),param_2);
    bVar3 = BVar2 != 0;
  }
  return bVar3;
}

