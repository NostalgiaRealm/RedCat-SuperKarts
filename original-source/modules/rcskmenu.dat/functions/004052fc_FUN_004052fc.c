/*
 * FUN_004052fc at 004052fc
 * undefined __register FUN_004052fc(int param_1)
 * Address ranges: 004052fc-00405359
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004052fc(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = DAT_0047b020;
  if ((DAT_0047b020 != (int *)0x0) && (DAT_0047b020[1] == param_1)) {
    DAT_0047b020 = (int *)*DAT_0047b020;
    FUN_0040272c((int)piVar2);
    return;
  }
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return;
    }
    piVar1 = (int *)*piVar2;
    if ((piVar1 != (int *)0x0) && (piVar1[1] == param_1)) break;
    piVar2 = (int *)*piVar2;
  }
  *piVar2 = *piVar1;
  FUN_0040272c((int)piVar1);
  return;
}

