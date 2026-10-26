/*
 * FUN_00471f9b at 00471f9b
 * undefined FUN_00471f9b(void)
 * Address ranges: 00471f9b-00471fe6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_00471f9b(void)

{
  char cVar1;
  uint uVar2;
  undefined4 unaff_EDI;
  char *pcVar3;
  undefined1 uStack00000018;
  
  FUN_004afee0(s__s__d____Unsupported_resolution___004f69e0,
               s_D__work_rcsk_Code_game_rrrmouse__004f6a04,0x31);
  uVar2 = 0xffffffff;
  *_uStack00000018 = uStack00000018;
  *(undefined4 *)(_uStack00000018 + 4) = unaff_EDI;
  *(undefined4 *)(_uStack00000018 + 8) = unaff_EDI;
  *(undefined4 *)(_uStack00000018 + 0xc) = unaff_EDI;
  pcVar3 = &DAT_004f6c20;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f6c20,~uVar2 - 1);
  return _uStack00000018;
}

