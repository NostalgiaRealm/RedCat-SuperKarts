/*
 * FUN_0042ee60 at 0042ee60
 * undefined FUN_0042ee60(void)
 * Address ranges: 0042ee60-0042ef87
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte FUN_0042ee60(void)

{
  int iVar1;
  byte bVar2;
  
  if (DAT_0053a5e8 == 0) {
    FUN_004afee0(s__handle_input_module__input_modu_004eac34);
  }
  if (DAT_0053a5d8 == 3) {
    FUN_004afee0(s__handle_input_module__trying_to_r_004eac7c);
  }
  if (DAT_0053a5d8 == 2) {
    FUN_004baac0();
  }
  iVar1 = FUN_004b3880(DAT_0053a5b8,DAT_0053a5dc);
  bVar2 = iVar1 != 0;
  iVar1 = FUN_004b3880(DAT_0053a5bc,DAT_0053a5dc);
  if (iVar1 != 0) {
    bVar2 = bVar2 | 2;
  }
  iVar1 = FUN_004b3880(DAT_0053a5c0,DAT_0053a5dc);
  if (iVar1 != 0) {
    bVar2 = bVar2 | 4;
  }
  iVar1 = FUN_004b3880(DAT_0053a5c4,DAT_0053a5dc);
  if (iVar1 != 0) {
    bVar2 = bVar2 | 8;
  }
  iVar1 = FUN_004b3880(DAT_0053a5c8,DAT_0053a5dc);
  if (iVar1 != 0) {
    bVar2 = bVar2 | 0x10;
  }
  iVar1 = FUN_004b3880(DAT_0053a5cc,DAT_0053a5dc);
  if (iVar1 != 0) {
    bVar2 = bVar2 | 0x20;
  }
  iVar1 = FUN_004b3880(DAT_0053a5d0,DAT_0053a5dc);
  if (iVar1 != 0) {
    bVar2 = bVar2 | 0x40;
  }
  iVar1 = FUN_004b3880(DAT_0053a5d4,DAT_0053a5dc);
  if (iVar1 != 0) {
    bVar2 = bVar2 | 0x80;
  }
  return bVar2;
}

