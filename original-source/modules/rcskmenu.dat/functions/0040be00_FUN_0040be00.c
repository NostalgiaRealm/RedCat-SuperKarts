/*
 * FUN_0040be00 at 0040be00
 * undefined __register FUN_0040be00(void)
 * Address ranges: 0040be00-0040be19
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040be00(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = '\x01';
  for (puVar2 = DAT_0047b2f4; (cVar1 != '\0' && (puVar2 != (undefined4 *)0x0));
      puVar2 = (undefined4 *)*puVar2) {
    cVar1 = (*(code *)puVar2[1])();
  }
  return;
}

