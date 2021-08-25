pushd models 
curl -O http://10.0.0.223:8000/models/checkpoint
curl -O http://10.0.0.223:8000/models/checkpoint_v2.index
curl -O http://10.0.0.223:8000/models/checkpoint_v2.data-00000-of-00001
popd