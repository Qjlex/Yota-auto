#!/bin/sh
run_program() {    
   $($@)           
   echo "$?"     
}

return_code=$(run_program "/bin/yota-auto")
if [[ $return_code == 0 ]]; then
      echo "[yota-auto] - Low internet enabled\n"
elif [[ $return_code == 1 ]]; then
      echo "[yota-auto] - Not enabled low internet\n"
fi