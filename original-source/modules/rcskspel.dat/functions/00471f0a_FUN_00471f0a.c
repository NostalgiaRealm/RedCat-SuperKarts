/*
 * FUN_00471f0a at 00471f0a
 * undefined FUN_00471f0a(void)
 * Address ranges: 00471f0a-00471f40
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_00471f0a(void)

{
  char cVar1;
  uint uVar2;
  undefined4 unaff_EDI;
  char *pcVar3;
  undefined1 uStack00000018;
  
  uVar2 = 0xffffffff;
  *_uStack00000018 = uStack00000018;
  *(undefined4 *)(_uStack00000018 + 4) = unaff_EDI;
  *(undefined4 *)(_uStack00000018 + 8) = unaff_EDI;
  *(undefined4 *)(_uStack00000018 + 0xc) = unaff_EDI;
  pcVar3 = (char *)&DAT_004f6c28;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f6c28,~uVar2 - 1);
  return _uStack00000018;
}

