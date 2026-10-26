/*
 * FUN_004bc090 at 004bc090
 * undefined FUN_004bc090(void)
 * Address ranges: 004bc090-004bc144
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004bc090(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  char *pcVar2;
  
  if (DAT_006b5d40 != (code *)0x0) {
    if (DAT_006ab950 == '\0') {
      FUN_004afce0(s__s__d____cd_rom_handlers_require_005025bc,
                   s_C__libraries_dxdraw_cdrom_cpp_00502600,0x36);
      return;
    }
    if (((param_3 == 0x8000) || (param_3 == 0x8004)) && (*(int *)(param_4 + 4) == 2)) {
      cVar1 = FUN_004c0c9e(DAT_006ab950);
      if ((*(uint *)(param_4 + 0xc) & 1 << (cVar1 + 0xbfU & 0x1f)) != 0) {
        (*DAT_006b5d40)(param_3 != 0x8000);
        pcVar2 = s_inserted_005025b0;
        if (param_3 != 0x8000) {
          pcVar2 = s_removed_005025a8;
        }
        FUN_004afce0(s__s__d____Game_CD_ROM_was__s_in_d_0050257c,
                     s_C__libraries_dxdraw_cdrom_cpp_00502600,0x4b,pcVar2,DAT_006ab950);
      }
    }
  }
  return;
}

