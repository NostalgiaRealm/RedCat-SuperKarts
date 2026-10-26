/*
 * FUN_0040ae64 at 0040ae64
 * undefined __register FUN_0040ae64(void)
 * Address ranges: 0040ae64-0040aec1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040ae64(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_10;
  undefined1 local_c;
  
  iVar1 = FUN_00402814();
  for (iVar3 = 0; (iVar3 < 7 && (iVar1 != (&DAT_0047b20c)[iVar3 * 2])); iVar3 = iVar3 + 1) {
  }
  if (iVar3 < 7) {
    piVar2 = FUN_0040ac64((int *)&DAT_00407268,'\x01',(undefined4 *)(&DAT_0047b210)[iVar3 * 2]);
  }
  else {
    local_c = 0;
    local_10 = iVar1;
    piVar2 = (int *)FUN_0040ad5c((int)&DAT_00407268,'\x01',(undefined4 *)PTR_PTR_0047c6a4,0,
                                 &local_10);
  }
  piVar2[3] = iVar1;
  return;
}

