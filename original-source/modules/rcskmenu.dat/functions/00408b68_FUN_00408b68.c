/*
 * FUN_00408b68 at 00408b68
 * undefined __register FUN_00408b68(undefined * param_1)
 * Address ranges: 00408b68-00408ba2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408b68(undefined *param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  float10 local_18;
  undefined *local_c;
  undefined1 local_8;
  
  pbVar1 = FUN_00403f94(param_1);
  uVar2 = FUN_0040cb14(pbVar1,&local_18,'\0');
  if ((char)uVar2 == '\0') {
    local_8 = 0xb;
    local_c = param_1;
    FUN_00407bc4((undefined4 *)PTR_PTR_0047c678,&local_c,0);
  }
  return;
}

