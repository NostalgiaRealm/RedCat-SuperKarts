/*
 * FUN_0040a74c at 0040a74c
 * undefined __register FUN_0040a74c(void)
 * Address ranges: 0040a74c-0040a7e2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a74c(void)

{
  LCID LVar1;
  CALID Calendar;
  undefined4 *puVar2;
  int extraout_ECX;
  int iVar3;
  undefined4 *in_FS_OFFSET;
  CALID Calendar_00;
  byte **ppbVar4;
  CALTYPE CVar5;
  undefined4 uStack_18;
  undefined1 *puStack_14;
  undefined1 *puStack_10;
  byte *local_8;
  
  puStack_10 = &stack0xfffffffc;
  local_8 = (byte *)0x0;
  puStack_14 = &LAB_0040a7e3;
  uStack_18 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_18;
  ppbVar4 = &local_8;
  LVar1 = GetThreadLocale();
  FUN_0040a4c4(LVar1,0x100b,(undefined4 *)&DAT_0040a7f8,(int *)ppbVar4);
  Calendar = FUN_00407fcc(local_8,1,extraout_ECX);
  if (Calendar - 3 < 3) {
    CVar5 = 4;
    Calendar_00 = Calendar;
    LVar1 = GetThreadLocale();
    EnumCalendarInfoA(FUN_0040a698,LVar1,Calendar_00,CVar5);
    iVar3 = 7;
    puVar2 = &DAT_0047d5d8;
    do {
      *puVar2 = 0xffffffff;
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    CVar5 = 3;
    LVar1 = GetThreadLocale();
    EnumCalendarInfoA(FUN_0040a6d4,LVar1,Calendar,CVar5);
  }
  *in_FS_OFFSET = uStack_18;
  puStack_10 = &LAB_0040a7ea;
  puStack_14 = (undefined1 *)0x40a7e2;
  FUN_00403b50((int *)&local_8);
  return;
}

