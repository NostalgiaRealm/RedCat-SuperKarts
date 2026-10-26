/*
 * FUN_00403978 at 00403978
 * undefined __register FUN_00403978(void)
 * Address ranges: 00403978-004039c4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00403978(void)

{
  ulonglong uVar1;
  uint uVar2;
  PVOID pvVar3;
  char *pcVar4;
  
  pcVar4 = s_Runtime_error_at_00000000_0047b034 + 0x10;
  uVar2 = DAT_0047d038;
  do {
    uVar1 = (ulonglong)uVar2;
    uVar2 = uVar2 / 10;
    *pcVar4 = (char)(uVar1 % 10) + '0';
    pcVar4 = pcVar4 + -1;
  } while (uVar2 != 0);
  pvVar3 = FUN_00404ec0(DAT_0047d040);
  uVar2 = (int)DAT_0047d040 - (int)pvVar3;
  pcVar4 = s_Runtime_error_at_00000000_0047b034 + 0x1c;
  do {
    *pcVar4 = (&DAT_0047b05c)[uVar2 & 0xf];
    pcVar4 = pcVar4 + -1;
    uVar2 = uVar2 >> 4;
  } while (uVar2 != 0);
  return;
}

