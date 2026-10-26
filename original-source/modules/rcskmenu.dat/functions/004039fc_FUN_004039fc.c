/*
 * FUN_004039fc at 004039fc
 * noreturn undefined __register FUN_004039fc(void)
 * Address ranges: 004039fc-00403aee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis marks this function no-return; verify that assumption against assembly before using its caller boundaries.
 */

void FUN_004039fc(void)

{
  code *pcVar1;
  undefined *puVar2;
  undefined1 *extraout_ECX;
  int iVar3;
  undefined4 extraout_EDX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  
  bVar6 = 0;
  pcVar1 = DAT_0047d03c;
  if (DAT_0047d4c8 == 0) {
    while (DAT_0047d03c = pcVar1, pcVar1 != (code *)0x0) {
      DAT_0047d03c = (code *)0x0;
      (*pcVar1)();
      pcVar1 = DAT_0047d03c;
    }
  }
  if (DAT_0047d040 != 0) {
    FUN_00403978();
    if (DAT_0047d048 == '\0') {
      if (DAT_0047b010 == '\0') {
        MessageBoxA((HWND)0x0,s_Runtime_error_at_00000000_0047b034,s_Error_0047b054,0);
      }
    }
    else {
      puVar2 = (undefined *)FUN_004059e0(&DAT_0047d21c,s_Runtime_error_at_00000000_0047b034);
      FUN_00405963(puVar2);
    }
    DAT_0047d040 = 0;
  }
  while( true ) {
    if ((DAT_0047d4c8 == 2) && (DAT_0047d038 == 0)) {
      DAT_0047d4b0 = 0;
    }
    FUN_0040384c();
    if (((DAT_0047d4c8 < 2) || (DAT_0047d038 != 0)) && (DAT_0047d4b4 != (undefined4 *)0x0)) {
      FUN_004053c8(DAT_0047d4b4,extraout_EDX,extraout_ECX);
      if ((HMODULE)DAT_0047d4b4[4] != (HMODULE)DAT_0047d4b4[1]) {
        FreeLibrary((HMODULE)DAT_0047d4b4[4]);
      }
    }
    FUN_00403824();
    if (DAT_0047d4c8 == 1) {
      (*DAT_0047d4cc)();
    }
    if (DAT_0047d4c8 != 0) {
      FUN_004039c8();
    }
    if (DAT_0047d4a4 == (undefined4 *)0x0) break;
    puVar4 = DAT_0047d4a4;
    puVar5 = &DAT_0047d4a4;
    for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
      puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  ExitProcess(DAT_0047d038);
}

