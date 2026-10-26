/*
 * FUN_0046c69c at 0046c69c
 * undefined __register FUN_0046c69c(int * param_1)
 * Address ranges: 0046c69c-0046c6cc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046c69c(int *param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = 0;
  do {
    bVar2 = (byte)uVar1 < 0xf;
    if ((byte)uVar1 < 0x10) {
      bVar2 = (*(byte *)((int)param_1 + ((int)(uVar1 & 0x7f) >> 3) + 0x28e) >> (uVar1 & 7) & 1) != 0
      ;
    }
    *(bool *)((int)param_1 + (uVar1 & 0xff) * 0x10 + 0x1fb) = bVar2;
    uVar1 = uVar1 + 1;
  } while ((char)uVar1 != '\t');
  (**(code **)(*param_1 + 0x74))();
  return;
}

