import axios from 'axios';

export default axios.create({
     baseURL: "https://api.unsplash.com",
     headers: {
         Authorization: 'Client-ID 6LBs2sl2iT2X9OZ1-A5WQy4STVolxsZi-WFSdaMvCMA'
     },
});
